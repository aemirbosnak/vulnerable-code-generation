#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int i = 0;

    printf("Enter text: ");

    // Deliberate buffer overflow on scanf
    scanf("%s", buffer);

    // Print the edited text
    printf("Edited text: %s", buffer);

    return 0;
}
