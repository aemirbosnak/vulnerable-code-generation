//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <math.h>
#include <sys/time.h>

#define MAX_SPEED 255

struct timeval start_time;
struct timeval current_time;
double elapsed_time;

int main() {
  // Initialize serial communication
  int fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
  if (fd == -1) {
    perror("open");
    return -1;
  }

  struct termios options;
  tcgetattr(fd, &options);
  options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
  tcsetattr(fd, TCSANOW, &options);

  // Initialize variables
  double desired_roll = 0;
  double desired_pitch = 0;
  double desired_throttle = 0;
  double desired_yaw = 0;

  // Main loop
  while (1) {
    // Get input from the user
    printf("Enter roll, pitch, throttle, yaw (in degrees): ");
    scanf("%lf %lf %lf %lf", &desired_roll, &desired_pitch, &desired_throttle, &desired_yaw);

    // Convert angles to radians
    desired_roll = desired_roll * M_PI / 180;
    desired_pitch = desired_pitch * M_PI / 180;
    desired_yaw = desired_yaw * M_PI / 180;

    // Calculate the desired motor speeds
    int motor1 = (int)(desired_throttle + desired_roll + desired_pitch + desired_yaw);
    int motor2 = (int)(desired_throttle + desired_roll - desired_pitch - desired_yaw);
    int motor3 = (int)(desired_throttle - desired_roll + desired_pitch - desired_yaw);
    int motor4 = (int)(desired_throttle - desired_roll - desired_pitch + desired_yaw);

    // Clamp the motor speeds to the maximum allowed value
    motor1 = motor1 > MAX_SPEED ? MAX_SPEED : motor1;
    motor2 = motor2 > MAX_SPEED ? MAX_SPEED : motor2;
    motor3 = motor3 > MAX_SPEED ? MAX_SPEED : motor3;
    motor4 = motor4 > MAX_SPEED ? MAX_SPEED : motor4;

    // Send the motor speeds to the drone
    char command[5];
    command[0] = (char)(motor1 & 0xFF);
    command[1] = (char)((motor1 >> 8) & 0xFF);
    command[2] = (char)(motor2 & 0xFF);
    command[3] = (char)((motor2 >> 8) & 0xFF);
    command[4] = (char)(motor3 & 0xFF);
    command[5] = (char)((motor3 >> 8) & 0xFF);
    command[6] = (char)(motor4 & 0xFF);
    command[7] = (char)((motor4 >> 8) & 0xFF);

    write(fd, command, 8);

    // Update the elapsed time
    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - start_time.tv_sec) + (current_time.tv_usec - start_time.tv_usec) / 1000000.0;
  }

  // Close the serial communication
  close(fd);

  return 0;
}