#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice;
    int light = 0, fan = 0, ac = 0;

    while (1) {
        printf("\nSmart Home System\n");
        printf("1. Toggle Light\n");
        printf("2. Toggle Fan\n");
        printf("3. Toggle AC\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                light = !light;
                printf("Light is now %s\n", light ? "ON" : "OFF");
                break;
            case 2:
                fan = !fan;
                printf("Fan is now %s\n", fan ? "ON" : "OFF");
                break;
            case 3:
                ac = !ac;
                printf("AC is now %s\n", ac ? "ON" : "OFF");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
