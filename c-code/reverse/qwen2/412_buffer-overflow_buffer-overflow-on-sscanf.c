#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[64];
    char *response = "250 OK\r\n";
    
    sscanf(response, "%s %*s", buffer);
    
    printf("Buffer: %s\n", buffer);
    
    return 0;
}
