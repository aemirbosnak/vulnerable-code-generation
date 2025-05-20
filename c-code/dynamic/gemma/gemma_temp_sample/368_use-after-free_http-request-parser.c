#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    char buffer[1024];
    int read_size = read(0, buffer, 1024);

    if (read_size > 0)
    {
        char* request_line = strstr(buffer, "GET") ? "GET" : strstr(buffer, "POST") ? "POST" : strstr(buffer, "PUT") ? "PUT" : strstr(buffer, "DELETE") ? "DELETE" : "";

        if (request_line)
        {
            printf("Request method: %s\n", request_line);
        }
    }

    return 0;
}
