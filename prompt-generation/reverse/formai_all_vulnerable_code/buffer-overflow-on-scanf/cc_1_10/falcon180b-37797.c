//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_NUM 1000
#define MAX_SUBNET_SIZE 1000

typedef struct {
    char* name;
    int num;
    int size;
} Subnet;

void createSubnet(Subnet* subnet, int num, int size) {
    subnet->name = malloc(strlen("subnet") + 4);
    sprintf(subnet->name, "subnet%d", num);
    subnet->num = num;
    subnet->size = size;
}

void printSubnet(Subnet subnet) {
    printf("Name: %s\n", subnet.name);
    printf("Number: %d\n", subnet.num);
    printf("Size: %d\n", subnet.size);
}

int main() {
    int num, size;
    char input[100];
    Subnet subnet;

    printf("Welcome to the surrealist subnet calculator!\n");
    printf("Please enter the number of subnets you would like to create:\n");
    scanf("%d", &num);

    printf("Please enter the name for the first subnet:\n");
    scanf("%s", input);
    createSubnet(&subnet, 1, atoi(input));

    for (int i = 2; i <= num; i++) {
        printf("Please enter the name for subnet %d:\n", i);
        scanf("%s", input);
        createSubnet(&subnet, i, atoi(input));
    }

    printf("Subnet list:\n");
    for (int i = 1; i <= num; i++) {
        printSubnet(subnet);
    }

    return 0;
}