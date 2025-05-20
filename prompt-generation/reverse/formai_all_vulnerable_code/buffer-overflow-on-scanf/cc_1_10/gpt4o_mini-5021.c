//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define DEVICE_PORT "/dev/ttyUSB0"
#define CMD_BUFFER_SIZE 256
#define STATUS_BUFFER_SIZE 128

volatile sig_atomic_t keepRunning = 1;

void handle_sigint(int sig) {
    keepRunning = 0;
}

void *drone_status_monitor(void *arg) {
    int fd = *((int *)arg);
    char status[STATUS_BUFFER_SIZE];

    while (keepRunning) {
        int bytes_read = read(fd, status, STATUS_BUFFER_SIZE - 1);
        if (bytes_read > 0) {
            status[bytes_read] = '\0';
            printf("Drone Status: %s\n", status);
        }
        usleep(100000); // Sleep for 100ms
    }

    return NULL;
}

void configure_port(int fd) {
    struct termios options;

    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_iflag |= IGNPAR;
    options.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &options);
}

void send_command(int fd, const char *command) {
    write(fd, command, strlen(command));
    printf("Sent Command: %s\n", command);
}

void print_menu() {
    printf("***** Drone Remote Control *****\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Up\n");
    printf("4. Move Down\n");
    printf("5. Rotate Left\n");
    printf("6. Rotate Right\n");
    printf("7. Move Forward\n");
    printf("8. Move Backward\n");
    printf("9. Exit\n");
    printf("********************************\n");
}

char *get_command(int choice) {
    switch (choice) {
        case 1: return "TAKEOFF\n";
        case 2: return "LAND\n";
        case 3: return "UP\n";
        case 4: return "DOWN\n";
        case 5: return "LEFT\n";
        case 6: return "RIGHT\n";
        case 7: return "FORWARD\n";
        case 8: return "BACKWARD\n";
        default: return NULL;
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    
    int fd = open(DEVICE_PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open_port: Unable to open the device");
        return EXIT_FAILURE;
    }

    configure_port(fd);
    
    pthread_t status_thread;
    pthread_create(&status_thread, NULL, drone_status_monitor, &fd);
    
    int choice;
    while (keepRunning) {
        print_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        if (choice == 9) {
            break;
        }
        
        const char *command = get_command(choice);
        if (command) {
            send_command(fd, command);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Shutting down the drone remote...\n");
    
    keepRunning = 0;
    pthread_join(status_thread, NULL);
    
    close(fd);
    printf("Disconnected from the drone. Goodbye!\n");
    return EXIT_SUCCESS;
}