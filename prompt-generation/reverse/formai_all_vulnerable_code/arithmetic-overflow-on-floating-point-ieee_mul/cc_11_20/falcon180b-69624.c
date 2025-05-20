//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double x, y, z;
  double theta, phi, psi;
  double dx, dy, dz;
  double dtheta, dphi, dpsi;
  int choice;

  printf("Welcome to the Drone Remote Control Program!\n");
  printf("Please enter the initial position (x y z): ");
  scanf("%lf %lf %lf", &x, &y, &z);

  printf("Please enter the initial orientation (theta phi psi): ");
  scanf("%lf %lf %lf", &theta, &phi, &psi);

  while (1) {
    printf("\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Move up\n");
    printf("5. Move down\n");
    printf("6. Hover\n");
    printf("7. Exit\n");
    printf("\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        dx = cos(theta) * cos(phi);
        dy = sin(theta) * cos(phi);
        dz = sin(phi);
        x += dx * 0.1;
        y += dy * 0.1;
        z += dz * 0.1;
        break;

      case 2:
        dtheta = 0.1;
        if (phi > M_PI / 2) {
          dphi = -0.1;
        } else {
          dphi = 0.1;
        }
        theta += dtheta;
        phi += dphi;
        break;

      case 3:
        dtheta = -0.1;
        if (phi < -M_PI / 2) {
          dphi = 0.1;
        } else {
          dphi = -0.1;
        }
        theta += dtheta;
        phi += dphi;
        break;

      case 4:
        dz = 0.1;
        z += dz;
        break;

      case 5:
        dz = -0.1;
        z += dz;
        break;

      case 6:
        printf("Hovering...\n");
        break;

      case 7:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice.\n");
    }

    printf("Current position: (%lf, %lf, %lf)\n", x, y, z);
    printf("Current orientation: (%lf, %lf, %lf)\n", theta, phi, psi);
  }

  return 0;
}