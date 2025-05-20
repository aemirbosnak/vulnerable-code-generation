//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <math.h>

typedef struct {
    volatile int x;
    volatile int y;
    volatile int z;
    volatile int yaw;
    volatile int pitch;
    volatile int roll;
} DroneControl;

volatile DroneControl *droneControl;

void handleSignal(int signum) {
    printf("Exiting...\n");
    munmap((void *)droneControl, 4096);
    exit(signum);
}

int main() {
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Can't open memory device");
        exit(1);
    }

    droneControl = (volatile DroneControl *) mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0x600);
    if (droneControl == NULL) {
        perror("Can't map memory");
        exit(1);
    }

    signal(SIGINT, handleSignal);

    while (1) {
        double angleX, angleY, angleZ;
        double throttle;

        scanf("%lf %lf %lf %lf", &angleX, &angleY, &angleZ, &throttle);

        angleX *= M_PI / 180.0;
        angleY *= M_PI / 180.0;
        angleZ *= M_PI / 180.0;

        droneControl->x = round(sin(angleX) * 1000.0);
        droneControl->y = round(sin(angleY) * 1000.0);
        droneControl->z = round(sin(angleZ) * 1000.0 + 1000.0);
        droneControl->yaw = round(throttle * 500.0);

        usleep(100000);
    }

    munmap((void *)droneControl, 4096);
    close(fd);

    return 0;
}