//FormAI DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str1[50], str2[50], str3[50];
    int choice, len1, len2, len3, i, j, k;
    char *head, *tail, *temp;
    char *s1, *s2, *s3;
    int done = 0;

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    len1 = strlen(str1);
    if (len1 > 0 && str1[len1-1] == '\n') {
        str1[--len1] = '\0';
    }

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    len2 = strlen(str2);
    if (len2 > 0 && str2[len2-1] == '\n') {
        str2[--len2] = '\0';
    }

    printf("Enter string 3: ");
    fgets(str3, sizeof(str3), stdin);
    len3 = strlen(str3);
    if (len3 > 0 && str3[len3-1] == '\n') {
        str3[--len3] = '\0';
    }

    while (!done)
    {
        printf("\nSelect an option:\n");
        printf("1. Reverse a string\n");
        printf("2. Convert to all lowercase\n");
        printf("3. Convert to all uppercase\n");
        printf("4. Remove whitespace\n");
        printf("5. Concatenate two strings\n");
        printf("6. Split a string into two\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Which string to reverse? (1-3): ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            head = s1;
            tail = s1 + strlen(s1) - 1;
            while (head < tail)
            {
                temp = *head;
                *head++ = *tail;
                *tail-- = temp;
            }
            printf("Reversed string %d: %s\n", i, s1);
            break;
        
        case 2:
            printf("Which string to convert to lowercase? (1-3): ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            for (j = 0; s1[j] != '\0'; j++)
            {
                if (s1[j] >= 'A' && s1[j] <= 'Z')
                {
                    s1[j] += 32;
                }
            }
            printf("Lowercase string %d: %s\n", i, s1);
            break;
        
        case 3:
            printf("Which string to convert to uppercase? (1-3): ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            for (j = 0; s1[j] != '\0'; j++)
            {
                if (s1[j] >= 'a' && s1[j] <= 'z')
                {
                    s1[j] -= 32;
                }
            }
            printf("Uppercase string %d: %s\n", i, s1);
            break;

        case 4:
            printf("Which string to remove whitespace? (1-3): ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            for (j = 0; s1[j] != '\0'; j++)
            {
                if (isspace(s1[j]))
                {
                    for (k = j; s1[k] != '\0'; k++)
                    {
                        s1[k] = s1[k+1];
                    }
                    j--;
                }
            }
            printf("Whitespace-free string %d: %s\n", i, s1);
            break;

        case 5:
            printf("Which strings to concatenate? (1-3): ");
            scanf("%d %d", &i, &j);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            switch (j)
            {
            case 1:
                s2 = str1;
                break;
            case 2:
                s2 = str2;
                break;
            case 3:
                s2 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            strcat(s1, s2);
            printf("Concatenated string: %s\n", s1);
            break;

        case 6:
            printf("Which string to split? (1-3): ");
            scanf("%d", &i);
            switch (i)
            {
            case 1:
                s1 = str1;
                break;
            case 2:
                s1 = str2;
                break;
            case 3:
                s1 = str3;
                break;
            default:
                printf("Invalid input.\n");
                break;
            }
            printf("Position at which to split string %d? (0-%d): ", i, strlen(s1)-1);
            scanf("%d", &j);
            s2 = (char *)malloc((j+1)*sizeof(char));
            s3 = (char *)malloc((strlen(s1)-j+1)*sizeof(char));
            strncpy(s2, s1, j);
            strncpy(s3, s1+j, strlen(s1)-j);
            s2[j] = '\0';
            s3[strlen(s1)-j] = '\0';
            printf("Split string %d: %s and %s\n", i, s2, s3);
            break;

        case 7:
            done = 1;
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid input.\n");
            break;
        }
    }
    return 0;
}