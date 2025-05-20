#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *log_message = NULL;
    printf("Attempting to dereference a null pointer...\n");
    *log_message = "This is a logged message";
    printf("Log message: %s\n", log_message);
    free(log_message);
    return 0;
}
