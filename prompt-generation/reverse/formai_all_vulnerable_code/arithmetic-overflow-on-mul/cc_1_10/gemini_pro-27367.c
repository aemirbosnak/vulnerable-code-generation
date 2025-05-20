//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <sys/reboot.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <errno.h>

#define BLKSIZE 512

#define swapon "/sbin/swapon"
#define swapoff "/sbin/swapoff"
#define newfs "/sbin/mkfs.ext4"
#define resize2fs "/sbin/resize2fs"

#define SHELL "/bin/sh"

int main(int argc, char **argv)
{
	int fd;
	struct hd_geometry geometry;
	unsigned long long start, end, swapsize;
	int swap;
	int rc;

	if (argc < 3) {
		printf("Usage: %s <device> <swapsize> [partition]\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Get the geometry of the device
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		return EXIT_FAILURE;
	}

	if (ioctl(fd, HDIO_GETGEO, &geometry) == -1) {
		perror("ioctl");
		close(fd);
		return EXIT_FAILURE;
	}

	close(fd);

	// Calculate the start and end of the swap partition
	start = atoll(argv[2]) * 2048;
	end = geometry.heads * geometry.sectors * geometry.cylinders;

	// Create the swap partition
	rc = system(newfs);
	if (rc != 0) {
		perror("mkfs.ext4");
		return EXIT_FAILURE;
	}

	// Activate the swap partition
	rc = system(swapon);
	if (rc != 0) {
		perror("swapon");
		return EXIT_FAILURE;
	}

	// Mount the root partition
	rc = mount("/dev/mmcblk0p1", "/", "ext4", MS_REMOUNT, NULL);
	if (rc != 0) {
		perror("mount");
		return EXIT_FAILURE;
	}

	// Resize the root partition
	rc = system(resize2fs);
	if (rc != 0) {
		perror("resize2fs");
		return EXIT_FAILURE;
	}

	// Reboot the system
	reboot(RB_AUTOBOOT);

	return EXIT_SUCCESS;
}