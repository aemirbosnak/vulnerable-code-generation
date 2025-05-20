#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];

    printf("Enter a message: ");
    scanf("%s", buffer);

    // Overflow on sscanf
    char exploit_string[] = "This string is too long and will cause an overflow!";
    int exploit_length = strlen(exploit_string) + 1;
    memcpy(buffer, exploit_string, exploit_length);

    printf("Your message: %s", buffer);

    return 0;
}
