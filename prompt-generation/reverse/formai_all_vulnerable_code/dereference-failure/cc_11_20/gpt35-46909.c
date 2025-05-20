//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#define STR_SIZE 100

int main()
{
    char str[STR_SIZE];
    int choice, len, len1, len2;
    char sub[STR_SIZE], sub1[STR_SIZE], sub2[STR_SIZE];
    char rev[STR_SIZE], upper[STR_SIZE], lower[STR_SIZE];

    printf("\nEnter the string : ");
    scanf("%[^\n]", str);

    len = strlen(str);

    while(1) //infinite loop for menu and input validation
    {
        printf("\n\nChoose the operation to perform:\n");
        printf("1. Extract a substring\n");
        printf("2. Reverse the string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Convert to lowercase\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //extract a substring
                printf("\nEnter the start index and length of substring: ");
                scanf("%d%d", &len1, &len2);

                if(len1+len2 > len) //if substring is beyond input string length
                {
                    printf("\nInvalid input! Substring is beyond string length.");
                    break;
                }
                else
                {
                    strncpy(sub, str+len1, len2); //copying substring to sub array
                    sub[len2] = '\0'; //adding null character to the end
                    printf("\nSubstring is: %s", sub);
                    break;
                }

            case 2: //reverse the string
                for(int i=0; i<len; i++)
                {
                    rev[i] = str[len-i-1]; //storing characters in reverse order
                }
                rev[len] = '\0'; //adding null character to the end
                printf("\nReversed string is : %s", rev);
                break;

            case 3: //convert to uppercase
                for(int i=0; i<len; i++)
                {
                    upper[i] = toupper(str[i]); //converting characters to uppercase and storing in upper array
                }
                upper[len] = '\0'; //adding null character to the end
                printf("\nString in uppercase is : %s", upper);
                break;

            case 4: //convert to lowercase
                for(int i=0; i<len; i++)
                {
                    lower[i] = tolower(str[i]); //converting characters to lowercase and storing in lower array
                }
                lower[len] = '\0'; //adding null character to the end
                printf("\nString in lowercase is : %s", lower);
                break;

            case 5: //exit
                printf("\nExiting the program!");
                exit(0);

            default:
                printf("\nInvalid input! Please choose a valid option.");
        }
    }

    return 0;
}