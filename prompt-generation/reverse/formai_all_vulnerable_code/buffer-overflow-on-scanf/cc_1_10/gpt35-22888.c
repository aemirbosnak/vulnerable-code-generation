//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

char *string_to_upper(char *str);
char *string_to_lower(char *str);
char *string_concat(char *str1, char *str2);
int string_compare(char *str1, char *str2);

int main()
{
    char str1[50], str2[50], *new_str;
    int option, cmp;

    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);

    while (1)
    {
        printf("\n1. Convert to uppercase\n2. Convert to lowercase\n3. Concatenate strings\n4. Compare strings\n5. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                new_str = string_to_upper(str1);
                printf("\n%s (uppercase)\n", new_str);
                free(new_str);
                break;

            case 2:
                new_str = string_to_lower(str1);
                printf("\n%s (lowercase)\n", new_str);
                free(new_str);
                break;

            case 3:
                new_str = string_concat(str1, str2);
                printf("\n%s (concatenated)\n", new_str);
                free(new_str);
                break;

            case 4:
                cmp = string_compare(str1, str2);
                if (cmp > 0)
                    printf("\n%s is greater than %s\n", str1, str2);
                else if (cmp < 0)
                    printf("\n%s is less than %s\n", str1, str2);
                else
                    printf("\n%s is equal to %s\n", str1, str2);
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("\nInvalid option\n");
                break;
        }
    }

    return 0;
}

char *string_to_upper(char *str)
{
    char *new_str = malloc(sizeof(char) * 50);
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            new_str[i] = str[i] - 32;
        else
            new_str[i] = str[i];

        i++;
    }

    new_str[i] = '\0';

    return new_str;
}

char *string_to_lower(char *str)
{
    char *new_str = malloc(sizeof(char) * 50);
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            new_str[i] = str[i] + 32;
        else
            new_str[i] = str[i];

        i++;
    }

    new_str[i] = '\0';

    return new_str;
}

char *string_concat(char *str1, char *str2)
{
    char *new_str = malloc(sizeof(char) * 100);
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        new_str[j] = str1[i];
        i++;
        j++;
    }

    i = 0;

    while (str2[i] != '\0')
    {
        new_str[j] = str2[i];
        i++;
        j++;
    }

    new_str[j] = '\0';

    return new_str;
}

int string_compare(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0' && str2[i] == '\0')
            break;
        i++;
    }

    return str1[i] - str2[i];
}