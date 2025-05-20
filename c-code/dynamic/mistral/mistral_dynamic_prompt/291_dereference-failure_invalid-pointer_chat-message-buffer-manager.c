#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void chat_message(char *buffer, int index) {
    char messages[][10] = {"Hello, World!", "What's up?", "Later, Gator."};
    if (index >= 0 && index < 3)
        strcpy(buffer, messages[index]);
    else
        printf("Invalid index.\n");
}

void main() {
    char buffer[10];
    int index = 42;

    printf("Enter a number between 0 and 2: ");
    scanf("%d", &index);

    chat_message(buffer, index);
    printf("\nYour message is: %s\n", buffer);

    char *bad_ptr = &buffer[15];
    printf("Address of the 16th character: %p\n", bad_ptr);
    printf("Value at the 16th character: %c\n", *bad_ptr);

    printf("Dereferencing an invalid pointer...\n");
    printf("%c\n", *buffer); // This line will cause a segmentation fault
}
