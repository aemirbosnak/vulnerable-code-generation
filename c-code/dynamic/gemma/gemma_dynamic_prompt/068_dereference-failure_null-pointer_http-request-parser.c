#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str = NULL;
    char** ptr = &str;

    *ptr = malloc(10);
    if (*ptr == NULL)
    {
        return 1;
    }

    (*ptr)[0] = 'H';
    (*ptr)[1] = 'T';
    (*ptr)[2] = 'T';
    (*ptr)[3] = 'P';
    (*ptr)[4] = 'A';
    (*ptr)[5] = 'C';
    (*ptr)[6] = '\0';

    printf("%s", str);

    free(str);
    return 0;
}
