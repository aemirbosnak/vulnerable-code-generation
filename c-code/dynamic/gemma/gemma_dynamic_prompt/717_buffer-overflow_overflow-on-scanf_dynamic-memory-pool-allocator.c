#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    return ptr;
}

void my_free(void *ptr)
{
    free(ptr);
}

int main()
{
    char *buf = NULL;
    int size = 0;

    printf("Enter the size of the memory block: ");
    scanf("%d", &size);

    buf = (char *)my_malloc(size);

    printf("Enter data for the memory block: ");
    scanf("%s", buf);

    my_free(buf);

    return 0;
}
