#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    char buffer[1024];

    printf("Enter a number: ");
    scanf("%d", &num);

    sprintf(buffer, "Log entry: %d", num);

    FILE *fp = fopen("log.txt", "a");
    fprintf(fp, "%s\n", buffer);
    fclose(fp);

    return 0;
}
