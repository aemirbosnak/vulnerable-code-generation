//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int choice, len, i;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    printf("\nSelect an option:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Remove spaces\n");
    printf("4. Reverse string\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i = 0; i < len; i++) {
                    if(str[i] >= 'a' && str[i] <= 'z') {
                        str[i] -= 32; //convert to uppercase
                    }
                }
                printf("\nString in uppercase: %s\n", str);
                break;

            case 2:
                for(i = 0; i < len; i++) {
                    if(str[i] >= 'A' && str[i] <= 'Z') {
                        str[i] += 32; //convert to lowercase
                    }
                }
                printf("\nString in lowercase: %s\n", str);
                break;

            case 3:
                for(i = 0; i < len; i++) {
                    if(str[i] == ' ') {
                        for(int j = i; j < len; j++) {
                            str[j] = str[j+1]; //shift all characters one position to the left to remove space
                        }
                        len--;
                    }
                }
                printf("\nString without spaces: %s\n", str);
                break;

            case 4:
                for(i = 0; i < len/2; i++) {
                    char temp = str[i];
                    str[i] = str[len-1-i]; //swap first and last characters, second and second last characters, and so on, to reverse string
                    str[len-1-i] = temp;
                }
                printf("\nReversed string: %s\n", str);
                break;

            case 5:
                printf("\nThanks for using the program!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}