//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    int choice, flag = 1;

    printf("Welcome to the Drone Remote Control Program!\n\n");
    printf("Enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! You are now in control of a drone.\n\n", input);

    do {
        printf("Choose an option:\n");
        printf("1. Take off\n");
        printf("2. Fly forward\n");
        printf("3. Fly backward\n");
        printf("4. Fly left\n");
        printf("5. Fly right\n");
        printf("6. Hover\n");
        printf("7. Land\n");
        printf("8. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Taking off...\n");
                break;
            case 2:
                printf("Flying forward...\n");
                break;
            case 3:
                printf("Flying backward...\n");
                break;
            case 4:
                printf("Flying left...\n");
                break;
            case 5:
                printf("Flying right...\n");
                break;
            case 6:
                printf("Hovering...\n");
                break;
            case 7:
                printf("Landing...\n");
                break;
            case 8:
                printf("Exiting program...\n");
                flag = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(flag);

    return 0;
}