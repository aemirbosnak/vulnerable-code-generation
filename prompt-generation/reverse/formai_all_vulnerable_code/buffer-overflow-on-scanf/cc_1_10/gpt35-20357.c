//FormAI DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];
   int choice;
   printf("Welcome to C String Manipulator!\n");

   do {
        printf("\nPlease choose an option:\n");
        printf("1. Length\n");
        printf("2. Copy\n");
        printf("3. Concatenate\n");
        printf("4. Compare\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Length
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Length of the string: %ld\n", strlen(str1));
                break;
            case 2: // Copy
                printf("Enter the source string: ");
                scanf("%s", str1);
                strcpy(str2, str1);
                printf("Source string: %s\nDestination string: %s\n", str1, str2);
                break;
            case 3: // Concatenate
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 4: // Compare
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                if(strcmp(str1, str2) == 0) {
                    printf("The strings are same.\n");
                }
                else {
                    printf("The strings are different.\n");
                }
                break;
            case 5: // Exit
                printf("Exiting the program. Thank you!\n");
                break;
            default: // Invalid option
                printf("Invalid option selected. Please choose a valid option.\n");
                break;
        }
   } while(choice != 5);

   return 0;
}