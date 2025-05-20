//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    void* ptr1;
    void* ptr2;
    void* ptr3;
    void* ptr4;
    int choice, free_choice;

    printf("\n***Memory Management Program***\n\n");
    while(1) {
        printf("Select an option:\n");
        printf("1. Allocate memory\n");
        printf("2. Free allocated memory\n");
        printf("3. View allocated memory\n");
        printf("4. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of memory to allocate in bytes: ");
                int size;
                scanf("%d", &size);

                printf("Allocating %d bytes of memory...\n", size);

                ptr1 = malloc(size);
                ptr2 = malloc(size/2);
                ptr3 = malloc(size*2);
                ptr4 = malloc(size*4);

                printf("Memory allocated successfully!\n");
                printf("Memory has been divided into four chunks.\n\n");
                break;

            case 2:
                printf("Which memory chunk would you like to free?\n");
                printf("1. %p\n", ptr1);
                printf("2. %p\n", ptr2);
                printf("3. %p\n", ptr3);
                printf("4. %p\n", ptr4);
                printf("5. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &free_choice);

                switch(free_choice) {
                    case 1:
                        free(ptr1);
                        printf("Memory at %p freed successfully!\n\n", ptr1);
                        break;

                    case 2:
                        free(ptr2);
                        printf("Memory at %p freed successfully!\n\n", ptr2);
                        break;

                    case 3:
                        free(ptr3);
                        printf("Memory at %p freed successfully!\n\n", ptr3);
                        break;

                    case 4:
                        free(ptr4);
                        printf("Memory at %p freed successfully!\n\n", ptr4);
                        break;

                    case 5:
                        printf("Exiting memory management program...\n");
                        exit(0);
                        break;

                    default:
                        printf("Invalid choice! Please try again.\n\n");
                        break;
                }
                break;

            case 3:
                printf("Viewing allocated memory...\n");
                printf("ptr1: %p\n", ptr1);
                printf("ptr2: %p\n", ptr2);
                printf("ptr3: %p\n", ptr3);
                printf("ptr4: %p\n\n", ptr4);
                break;

            case 4:
                printf("Exiting memory management program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    return 0;
}