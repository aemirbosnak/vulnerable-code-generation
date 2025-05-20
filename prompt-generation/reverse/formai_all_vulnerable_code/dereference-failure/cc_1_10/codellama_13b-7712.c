//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: brave
/*
 * File Backup System
 *
 * Created by [Your Name]
 * Date: [Date]
 *
 * This program is a simple file backup system that allows users to backup files
 * to a designated directory. The program takes in a source directory and a
 * destination directory as arguments, and copies all files from the source
 * directory to the destination directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096

// Structure to store file information
struct file_info {
	char *name;
	char *path;
	struct stat stat_buf;
};

// Function to copy a file
void copy_file(const char *src, const char *dest) {
	int src_fd, dest_fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	// Open the source file
	src_fd = open(src, O_RDONLY);
	if (src_fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	// Open the destination file
	dest_fd = open(dest, O_WRONLY | O_CREAT, 0666);
	if (dest_fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	// Read data from the source file and write it to the destination file
	while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	// Close the source and destination files
	close(src_fd);
	close(dest_fd);
}

// Function to copy all files in a directory
void copy_directory(const char *src, const char *dest) {
	DIR *dir;
	struct dirent *entry;
	struct stat stat_buf;
	char src_path[BUFFER_SIZE], dest_path[BUFFER_SIZE];

	// Open the directory
	dir = opendir(src);
	if (dir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	// Read the directory entries
	while ((entry = readdir(dir)) != NULL) {
		// Skip the "." and ".." entries
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}

		// Construct the source and destination paths
		snprintf(src_path, BUFFER_SIZE, "%s/%s", src, entry->d_name);
		snprintf(dest_path, BUFFER_SIZE, "%s/%s", dest, entry->d_name);

		// Get the file information
		if (lstat(src_path, &stat_buf) == -1) {
			perror("lstat");
			exit(EXIT_FAILURE);
		}

		// Copy the file
		if (S_ISREG(stat_buf.st_mode)) {
			copy_file(src_path, dest_path);
		} else if (S_ISDIR(stat_buf.st_mode)) {
			copy_directory(src_path, dest_path);
		}
	}

	// Close the directory
	closedir(dir);
}

int main(int argc, char *argv[]) {
	// Check the number of arguments
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Copy the files
	copy_directory(argv[1], argv[2]);

	return 0;
}