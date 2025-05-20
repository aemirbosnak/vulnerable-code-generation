#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char message_buffer[1024];
    char message[2048];

    printf("Enter a message: ");
    scanf("%s", message);

    strcpy(message_buffer, message);

    printf("Your message: %s", message_buffer);

    return 0;
}
