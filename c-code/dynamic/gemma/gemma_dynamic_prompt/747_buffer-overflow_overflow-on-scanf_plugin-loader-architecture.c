#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void plugin_loader()
{
    char buffer[1024];
    scanf("%s", buffer);
    printf("%s", buffer);
}

int main()
{
    plugin_loader();
    return 0;
}
