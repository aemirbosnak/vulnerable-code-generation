#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void process_image(char *image_data, int size) {
    char buffer[MAX_IMAGE_SIZE];
    printf("Enter image data: ");
    scanf("%s", buffer);
    if (strlen(buffer) > MAX_IMAGE_SIZE - 1) {
        printf("Buffer overflow detected!\n");
    } else {
        strcpy(image_data, buffer);
        printf("Image processed successfully.\n");
    }
}

int main() {
    char image_data[MAX_IMAGE_SIZE];
    int choice;

    while (1) {
        printf("\nImage Processing Filter\n");
        printf("1. Process Image\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process_image(image_data, MAX_IMAGE_SIZE);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
