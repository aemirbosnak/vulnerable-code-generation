//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

int main() {
    int topology[MAX][MAX], n, i, j, k;
    char v[MAX][16], ip[MAX][16], c;
    printf("Enter the number of devices in the network: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the name of device %d: ", i+1);
        scanf("%s", v[i]);
        printf("Enter the IP address of device %d: ", i+1);
        scanf("%s", ip[i]);
    }
    //Setting up the initial topology
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            topology[i][j] = 0;
        }
    }
    while(1) {
        printf("Do you want to add a connection? (y/n): ");
        scanf(" %c", &c);
        if(c == 'n' || c == 'N') {
            break;
        }
        printf("Enter the name of device 1: ");
        char a[16], b[16];
        scanf("%s", a);
        printf("Enter the name of device 2: ");
        scanf("%s", b);
        int index1, index2;
        for(i = 0; i < n; i++) {
            if(strcmp(a, v[i]) == 0) {
                index1 = i;
            }
            if(strcmp(b, v[i]) == 0) {
                index2 = i;
            }
        }
        topology[index1][index2] = 1;
        topology[index2][index1] = 1;
    }
    printf("\n\nThe network topology is as follows:\n\n");
    for(i = 0; i < n; i++) {
        printf("%s (%s) is connected to: ", v[i], ip[i]);
        for(j = 0; j < n; j++) {
            if(topology[i][j] == 1) {
                printf("%s, ", v[j]);
            }
        }
        printf("\n");
    }
    return 0;
}