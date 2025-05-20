#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    scanf("%s", name);

    if (strlen(name) > 10)
    {
        printf("Error: name too long.\n");
        return 1;
    }

    printf("Hello, %s, welcome to the haunted house.\n", name);

    char choice;
    printf("You hear a noise. Do you want to (a) investigate or (b) flee?\n");
    scanf(" %c", &choice);

    switch (choice)
    {
        case 'a':
            printf("You explore the house and find a hidden room.\n");
            break;
        case 'b':
            printf("You flee the house and escape the evil spirit.\n");
            break;
        default:
            printf("Invalid input.\n");
            return 1;
    }

    return 0;
}
