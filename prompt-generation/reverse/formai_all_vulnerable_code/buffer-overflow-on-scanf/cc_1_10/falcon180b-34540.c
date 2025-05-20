//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Function to calculate checksum
int calculate_checksum(char *data, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

// Function to print menu
void print_menu() {
    printf("\n");
    printf("MENU\n");
    printf("1. Enter data\n");
    printf("2. Calculate checksum\n");
    printf("3. Exit\n");
    printf("\n");
}

int main() {
    char data[1000];
    int length = 0;
    int choice;

    while (TRUE) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data (max 1000 characters): ");
            scanf("%[^\n]", data);
            length = strlen(data);
            break;
        case 2:
            if (length == 0) {
                printf("No data entered.\n");
            } else {
                int checksum = calculate_checksum(data, length);
                printf("Checksum: %d\n", checksum);
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}