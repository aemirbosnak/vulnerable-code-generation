#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    char *ptr = buffer;
    int n;

    printf("Enter the number of bytes to read: ");
    scanf("%d", &n);

    if (n > 1024)
    {
        printf("Error: Invalid input.\n");
        exit(1);
    }

    printf("Enter the HTTP request: ");
    scanf("%s", ptr);

    printf("The HTTP request is: %s\n", buffer);

    return 0;
}
