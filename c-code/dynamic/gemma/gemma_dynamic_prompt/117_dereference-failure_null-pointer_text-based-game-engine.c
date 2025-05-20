#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = NULL;
    printf("Enter a command: ");
    scanf("%s", str);

    if (str)
    {
        printf("You entered: %s\n", str);
        free(str);
    }

    return 0;
}
