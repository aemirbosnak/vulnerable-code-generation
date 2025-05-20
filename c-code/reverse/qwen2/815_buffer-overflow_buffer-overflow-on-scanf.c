#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_DEVICES 3

int main() {
    int choice;
    char devices[MAX_DEVICES][20] = {"Light", "Fan", "AC"};
    int status[MAX_DEVICES] = {0};

    while (1) {
        printf("Smart Home System\n");
        printf("1. Toggle Light\n");
        printf("2. Toggle Fan\n");
        printf("3. Toggle AC\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        if (choice >= 1 && choice <= MAX_DEVICES) {
            status[choice - 1] = !status[choice - 1];
            printf("%s is now %s\n", devices[choice - 1], status[choice - 1] ? "ON" : "OFF");
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
