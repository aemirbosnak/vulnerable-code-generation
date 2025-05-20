//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;
    int j = 0;
    int k = 0;
    int *ptr;
    int size = 1024;

    printf("RAM Usage Monitor\n");
    printf("-----------------\n");

    while(1) {
        printf("\n");
        printf("Total RAM: %d bytes\n", size);
        printf("Used RAM: %d bytes\n", k);
        printf("Free RAM: %d bytes\n", size - k);

        printf("\n");
        printf("Press 1 to allocate memory\n");
        printf("Press 2 to deallocate memory\n");
        printf("Press 3 to exit\n");

        scanf("%d", &i);

        switch(i) {
            case 1:
                printf("Enter the size of memory to allocate: ");
                scanf("%d", &j);
                ptr = (int*) malloc(j);
                if(ptr == NULL) {
                    printf("Error: Memory allocation failed\n");
                } else {
                    printf("Memory allocated successfully\n");
                    k += j;
                }
                break;
            case 2:
                printf("Enter the size of memory to deallocate: ");
                scanf("%d", &j);
                free(ptr);
                k -= j;
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}