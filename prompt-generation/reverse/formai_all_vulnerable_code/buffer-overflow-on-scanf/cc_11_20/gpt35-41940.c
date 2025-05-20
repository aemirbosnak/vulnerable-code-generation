//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int choice, length;
    char search_char, replace_char;

    printf("Enter a string: ");
    scanf("%s", string);
    length = strlen(string); // Calculate the length of the input string

    do {
        printf("\n\nPlease choose from the following options:\n\n");
        printf("1. Print the string in reverse order.\n");
        printf("2. Count the number of vowels in the string.\n");
        printf("3. Replace a character in the string.\n");
        printf("4. Exit the program.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            {
                printf("\nThe string in reverse order is: ");
                for (int i = length - 1; i >= 0; i--) {
                    printf("%c", string[i]);
                }
                break;
            }
            case 2:
            {
                int count = 0;
                char vowels[] = {'a', 'e', 'i', 'o', 'u'};
                for (int i = 0; i < length; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (string[i] == vowels[j]) {
                            count++;
                        }
                    }
                }
                printf("\nThe number of vowels in the string is: %d", count);
                break;
            }
            case 3:
            {
                printf("\nEnter the character you want to replace: ");
                scanf(" %c", &search_char); // Add whitespace before %c to consume the newline character
                printf("Enter the character you want to replace it with: ");
                scanf(" %c", &replace_char);

                for (int i = 0; i < length; i++) {
                    if (string[i] == search_char) {
                        string[i] = replace_char;
                    }
                }
                printf("\nThe new string is: %s", string);
                break;
            }
            case 4:
            {
                printf("\nExiting the program. Thank you!\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice. Please choose again.\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}