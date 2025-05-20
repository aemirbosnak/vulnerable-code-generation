//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char c;
    int len;
    int choice;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    printf("\nSelect one of the following operations:\n1. Capitalize first letter of each word\n2. Replace vowels with *\n3. Remove extra spaces\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nCapitalized string: ");
            for (int i = 0; i < len; i++) {
                if(str[i] == ' ')
                    printf("%c", str[i]);
                else if(i == 0 || str[i - 1] == ' ')
                    printf("%c", toupper(str[i]));
                else
                    printf("%c", str[i]);
            }
            break;
        case 2:
            printf("\nString with replaced vowels: ");
            for (int i = 0; i < len; i++) {
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                    printf("*");
                else
                    printf("%c", str[i]);
            }
            break;
        case 3:
            printf("\nString with removed extra spaces: ");
            c = str[0];
            printf("%c", c);
            for (int i = 1; i < len; i++) {
                if ((c == ' ' || c == '\t') && (str[i] == ' ' || str[i] == '\t'))
                    continue;
                else if (c == ' ' && str[i] == '\n')
                    continue;
                else {
                    printf("%c", str[i]);
                    c = str[i];
                }
            }
            break;
        default:
            printf("\nInvalid choice! Please choose again.");
            break;
    }

    return 0;
}