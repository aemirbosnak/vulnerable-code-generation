//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100], str1[100], str2[100];
    int choice; 

    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; //removes newline character

    printf("\nYour input: %s\n", input);

    printf("\nChoose the operation:\n");
    printf("1. Convert all characters to upper case.\n");
    printf("2. Convert all characters to lower case.\n");
    printf("3. Capitalize first character of each word.\n");
    printf("4. Concatenate two strings.\n");
    printf("5. Reverse the string.\n");
    printf("6. Exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(str1, input);
            for(int i=0; i<strlen(str1); i++){
                str1[i] = toupper(str1[i]);
            }
            printf("\nResult: %s", str1);
            break;

        case 2:
            strcpy(str1, input);
            for(int i=0; i<strlen(str1); i++){
                str1[i] = tolower(str1[i]);
            }
            printf("\nResult: %s", str1);
            break;

        case 3:
            strcpy(str1, input);
            char* token = strtok(str1, " ");
            while(token != NULL){
                token[0] = toupper(token[0]);
                printf("%s ", token);
                token = strtok(NULL, " ");
            }
            break;

        case 4:
            printf("\nEnter another string to concatenate: ");
            scanf(" %[^\n]s", str2);
            strcat(input, str2);
            printf("\nResult: %s", input);
            break;

        case 5:
            strcpy(str1, input);
            int j = strlen(str1)-1;
            for(int i=0; i<j; i++){ 
                char temp = str1[i];
                str1[i] = str1[j];
                str1[j--] = temp;
            }
            printf("\nResult: %s", str1);
            break;

        case 6:
            printf("\nGoodbye!");
            return 0;
            break;

        default:
            printf("\nInvalid choice. Try again!\n");
            break;
    }
    return 0;
}