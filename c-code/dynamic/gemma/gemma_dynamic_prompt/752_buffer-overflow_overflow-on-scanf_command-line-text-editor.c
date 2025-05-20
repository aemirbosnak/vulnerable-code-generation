#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buf[1024];
    int i = 0;

    printf("Enter text: ");

    // Vulnerable code - overflows scanf buffer
    scanf("%s", buf);

    // Print the edited text
    printf("Your text: %s\n", buf);

    return 0;
}
