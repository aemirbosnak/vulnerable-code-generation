//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IPS 50
#define MAX_NETS 10
#define MAX_MASK_LEN 16
#define MAX_SUBNETS 10
#define MAX_GATEWAYS 5

typedef struct {
    unsigned int ip[4];
    unsigned int mask[4];
    unsigned int net[4];
    unsigned int subnet[4];
    unsigned int gateway[4];
} CalcData;

void print_binary(unsigned int num) {
    int i;
    char bin[33];
    for (i = 31; i >= 0; i--) {
        bin[i] = (num >> i & 1) + '0';
        if (i == 24) bin[i] = '/';
        if (i == 0) bin[i+1] = '\0';
    }
    printf("%s\n", bin);
}

void calculate(CalcData *data, int net, int mask_len, int subnet, int gateway) {
    int i;

    memset(data->net, 0, sizeof(unsigned int) * 4);
    memset(data->subnet, 0, sizeof(unsigned int) * 4);
    memset(data->gateway, 0, sizeof(unsigned int) * 4);

    for (i = 0; i < 4; i++) {
        data->net[i] = data->ip[i] & (~((1 << (8 - mask_len)) - 1));
        data->subnet[i] = data->net[i] + ((subnet << (8 - mask_len)) & (~((1 << (8 - mask_len)) - 1)));
        data->gateway[i] = data->subnet[i];
    }

    if (gateway > 0) {
        for (i = 0; i < 4; i++) {
            data->gateway[i] += (gateway + 1) * (1 << (8 - mask_len));
        }
    }

    print_binary(data->net[0] | (data->net[1] << 8) | (data->net[2] << 16) | (data->net[3] << 24));
    printf(".");
    print_binary(data->net[1]);
    printf(".");
    print_binary(data->net[2]);
    printf(".");
    print_binary(data->net[3]);
    printf(" NetID: %d, NetMask: %d, Subnet: %d, Gateway: %d\n", net, mask_len, subnet, gateway);
    print_binary(data->subnet[0] | (data->subnet[1] << 8) | (data->subnet[2] << 16) | (data->subnet[3] << 24));
    printf(".");
    print_binary(data->subnet[1]);
    printf(".");
    print_binary(data->subnet[2]);
    printf(".");
    print_binary(data->subnet[3]);
    print_binary(data->gateway[0] | (data->gateway[1] << 8) | (data->gateway[2] << 16) | (data->gateway[3] << 24));
    printf(".\n");
}

int main() {
    int i, j, net, mask_len, subnet, gateway;
    CalcData data[MAX_IPS];

    for (i = 0; i < 5; i++) {
        printf("IP #%d:\n", i + 1);
        scanf("%d.%d.%d.%d", &data[i].ip[0], &data[i].ip[1], &data[i].ip[2], &data[i].ip[3]);

        printf("NetID: ");
        scanf("%d", &net);
        printf("Mask length: ");
        scanf("%d", &mask_len);

        for (j = 0; j < MAX_SUBNETS + MAX_GATEWAYS && net > 0; j++) {
            printf("Subnet #%d: ", j + 1);
            scanf("%d", &subnet);
            printf("Gateway: ");
            scanf("%d", &gateway);

            calculate(&data[i], net, mask_len, subnet, gateway);
        }

        printf("\n");
    }

    return 0;
}