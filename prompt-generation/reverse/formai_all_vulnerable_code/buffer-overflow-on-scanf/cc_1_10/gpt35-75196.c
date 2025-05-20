//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char ip_address[16];
    char subnet_mask[16];
    char *ptr;

    printf("Enter the IP Address: ");
    scanf("%s", ip_address);

    printf("Enter the Subnet Mask: ");
    scanf("%s", subnet_mask);

    int i, j, k;
    int n[4], m[4], b[4], a[4], p[4], q[4];

    ptr = strtok(ip_address, ".");
    i = 0;
    while(ptr != NULL) {
        n[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    ptr = strtok(subnet_mask, ".");
    j = 0;
    while(ptr != NULL) {
        m[j++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    for(i = 0; i < 4; i++) {
        b[i] = n[i] & m[i];
        p[i] = n[i] & (~m[i]);
    }

    for(i = 0; i < 4; i++) {
        q[i] = b[i];
    }

    printf("\n\n");
    printf("IP Address: %d.%d.%d.%d\n", n[0], n[1], n[2], n[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", m[0], m[1], m[2], m[3]);

    printf("\n\nCalculated Details:\n\n");

    printf("Binary IP Address: ");
    for(i = 0; i < 4; i++) {
        printf("%08d", byte_to_binary(n[i]));
        if(i < 3) {
            printf(".");
        }
    }

    printf("\nBinary subnet mask: ");
    for(i = 0; i < 4; i++) {
        printf("%08d", byte_to_binary(m[i]));
        if(i < 3) {
            printf(".");
        }
    }

    printf("\nNetwork Address: %d.%d.%d.%d\n", b[0], b[1], b[2], b[3]);

    printf("Binary Network Address: ");
    for(i = 0; i < 4; i++) {
        printf("%08d", byte_to_binary(b[i]));
        if(i < 3) {
            printf(".");
        }
    }

    printf("\nNumber of Hosts: %d\n", get_hosts_number(m));

    printf("\n\nIP Address Range:\n\n");

    printf("    %d.%d.%d.%d - ", b[0], b[1], b[2], b[3]);
    for(i = 3; i >= 0; i--) {
        if((b[i] + 1) == 256 && i != 0) {
            printf("0");
            if(i != 1) {
                printf(".");
            }
        } else {
            printf("%d", b[i] + 1);
            if(i != 0) {
                printf(".");
            }
            break;
        }
    }

    printf(" %d.%d.%d.%d\n", p[0], p[1], p[2], p[3]);

    printf("\n\nBroadcast Address: %d.%d.%d.%d\n", q[0] | (~m[0] & 255), q[1] | (~m[1] & 255), q[2] | (~m[2] & 255), q[3] | (~m[3] & 255));

    return 0;
}

int byte_to_binary(int n) {
    int binary = 0, rem, i = 1;
    while(n != 0) {
        rem = n % 2;
        n = n / 2;
        binary = binary + rem * i;
        i = i * 10;
    }
    return binary;
}

int get_hosts_number(int m[]) {
    int count = 0, i;
    for(i = 0; i < 4; i++) {
        if(m[i] == 255) {
            count += 8;
        } else {
            int ip_byte = byte_to_binary(m[i]);
            int j = 7, flag = 0;
            while(ip_byte != 0) {
                if(ip_byte % 10 == 1) {
                    flag = 1;
                    count++;
                }
                ip_byte /= 10;
                j--;
            }
            if(flag == 0) {
                break;
            }
        }
    }
    return (int)(pow(2, (double)count) - 2);
}