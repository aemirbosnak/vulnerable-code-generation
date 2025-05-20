//MISTRAL-7B DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>

#define ADDR 0x60000000
#define SIZE 0x1000

typedef struct {
    volatile unsigned int data[128];
} Robot_t;

Robot_t *robot;

void move_robot(int x, int y, int z) {
    robot->data[0] = (1 << 0) | ((x & 0xFF) << 8) | ((y & 0xFF) << 16) | ((z & 0xFF) << 24);
}

int main() {
    int fd;
    void *addr;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Error opening /dev/mem\n");
        exit(1);
    }

    addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, ADDR);
    if (addr == MAP_FAILED) {
        perror("Error mapping /dev/mem to memory\n");
        exit(1);
    }

    robot = (Robot_t *) addr;

    printf("*** SHOCKED ROBOT CONTROL ***\n");

    move_robot(0, 0, 50); // Move forward with shock
    sleep(1);

    move_robot(50, 0, 0); // Move left with shock
    sleep(1);

    move_robot(0, -50, 0); // Move backward with shock
    sleep(1);

    move_robot(0, 0, -50); // Move down with shock
    sleep(1);

    printf("*** ROBOT MOVED IN SHOCKED STYLE ***\n");

    munmap(addr, SIZE);
    close(fd);

    return 0;
}