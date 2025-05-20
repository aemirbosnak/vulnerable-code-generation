#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    char buffer[256];
    printf("Enter PASV response: ");
    fgets(buffer, sizeof(buffer), stdin);

    char data_port_str[6];
    sscanf(buffer, "PASV %[^)]", data_port_str);
    char *end;
    unsigned short data_port = strtoul(data_port_str, &end, 10);

    if (end - data_port_str == strlen(data_port_str)) {
        printf("Invalid data port.\n");
        return 1;
    }

    printf("Data port: %hu\n", data_port);
    return 0;
}
