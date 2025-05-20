#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[10] = "Hello, world!";
    char input[1024] = "";

    printf("Enter a string: ");
    scanf("%s", input);

    if (strlen(input) > 10)
    {
        printf("Error: input too long.\n");
    }
    else
    {
        strcpy(buffer, input);
        printf("Your string is: %s\n", buffer);
    }

    return 0;
}
