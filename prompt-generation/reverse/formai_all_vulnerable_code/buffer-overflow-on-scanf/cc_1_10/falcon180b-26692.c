//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int length;
    int prefix;
} Subnet;

Subnet *create_subnet(char *name, int length, int prefix) {
    Subnet *subnet = (Subnet *)malloc(sizeof(Subnet));
    if (subnet == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    subnet->name = strdup(name);
    subnet->length = length;
    subnet->prefix = prefix;
    return subnet;
}

int main() {
    char input[100];
    Subnet *subnet = NULL;
    int valid_input = 0;

    while (valid_input == 0) {
        printf("Enter the subnet name (max 80 characters): ");
        scanf("%s", input);
        if (strlen(input) > 80) {
            printf("Error: Subnet name is too long.\n");
        } else {
            valid_input = 1;
        }
    }

    while (valid_input == 0) {
        printf("Enter the subnet length (1-32): ");
        scanf("%d", &subnet->length);
        if (subnet->length < 1 || subnet->length > 32) {
            printf("Error: Subnet length is invalid.\n");
        } else {
            valid_input = 1;
        }
    }

    while (valid_input == 0) {
        printf("Enter the subnet prefix (1-32): ");
        scanf("%d", &subnet->prefix);
        if (subnet->prefix < 1 || subnet->prefix > 32) {
            printf("Error: Subnet prefix is invalid.\n");
        } else {
            valid_input = 1;
        }
    }

    printf("Subnet name: %s\n", subnet->name);
    printf("Subnet length: %d\n", subnet->length);
    printf("Subnet prefix: %d\n", subnet->prefix);

    return 0;
}