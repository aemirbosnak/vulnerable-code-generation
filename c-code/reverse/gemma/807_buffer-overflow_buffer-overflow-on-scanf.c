#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char input[10];
    printf("Enter the secret code: ");
    scanf("%s", input);

    if (strlen(input) > 9)
    {
        printf("Error: Input too long.\n");
    }
    else if (strcmp(input, "treasure") == 0)
    {
        printf("Congratulations! You found the treasure!\n");
    }
    else
    {
        printf("Incorrect code. Try again.\n");
    }

    return 0;
}
