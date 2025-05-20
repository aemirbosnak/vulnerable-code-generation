//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_CHAR_SIZE 50 // maximum size of a character

int main() {

    char arr[MAX_SIZE][MAX_CHAR_SIZE]; // array to store strings
    int n = 0; // number of strings
    int choice; // user choice

    do {
        printf("\n\n=====================================================\n");
        printf("1. Add a string\n");
        printf("2. Search for a string\n");
        printf("3. Display all strings\n");
        printf("4. Exit\n");
        printf("=====================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // add a string
                printf("Enter the string: ");
                scanf("%s", arr[n]);
                n++;
                break;

            case 2: // search for a string
                printf("Enter the string to search for: ");
                char search[MAX_CHAR_SIZE];
                scanf("%s", search);

                int found = 0;
                for(int i=0; i<n; i++) {
                    if(strcmp(arr[i], search) == 0) {
                        printf("String found at index %d\n", i);
                        found = 1;
                    }
                }
                if(!found) {
                    printf("String not found\n");
                }
                break;

            case 3: // display all strings
                printf("All strings:\n");
                for(int i=0; i<n; i++) {
                    printf("%s\n", arr[i]);
                }
                break;

            case 4: // exit
                printf("Exiting...\n");
                break;

            default: // invalid choice
                printf("Invalid choice\n");

        }
        printf("\n\n=====================================================\n");

    } while(choice!= 4);

    return 0;
}