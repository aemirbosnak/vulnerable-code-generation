//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s start_ip end_ip\n", argv[0]);
        return 1;
    }

    char *start_ip = argv[1];
    char *end_ip = argv[2];

    char *ip = argv[1];

    char *ip_parts[4];
    char *ip_part;
    int num_parts;

    num_parts = sscanf(ip, "%d.%d.%d.%d", &ip_part[0], &ip_part[1], &ip_part[2], &ip_part[3]);

    if (num_parts!= 4) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    char *start_ip_parts[4];
    char *start_ip_part;
    int start_ip_num_parts;

    start_ip_num_parts = sscanf(start_ip, "%d.%d.%d.%d", &start_ip_part[0], &start_ip_part[1], &start_ip_part[2], &start_ip_part[3]);

    if (start_ip_num_parts!= 4) {
        printf("Invalid IP address: %s\n", start_ip);
        return 1;
    }

    char *end_ip_parts[4];
    char *end_ip_part;
    int end_ip_num_parts;

    end_ip_num_parts = sscanf(end_ip, "%d.%d.%d.%d", &end_ip_part[0], &end_ip_part[1], &end_ip_part[2], &end_ip_part[3]);

    if (end_ip_num_parts!= 4) {
        printf("Invalid IP address: %s\n", end_ip);
        return 1;
    }

    int start_ip_num = atoi(start_ip_part[0]);
    int end_ip_num = atoi(end_ip_part[0]);
    int start_ip_num_high = start_ip_num + 1;
    int end_ip_num_low = end_ip_num - 1;

    if (start_ip_num_high < end_ip_num_low) {
        printf("Invalid IP address range: %s-%s\n", start_ip, end_ip);
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (start_ip_part[i] > end_ip_part[i]) {
            printf("Invalid IP address range: %s-%s\n", start_ip, end_ip);
            return 1;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (start_ip_parts[i]!= start_ip_part[i] || end_ip_parts[i]!= end_ip_part[i]) {
            printf("Invalid IP address range: %s-%s\n", start_ip, end_ip);
            return 1;
        }
    }

    if (ip_parts[0] < start_ip_parts[0] || ip_parts[0] > end_ip_parts[0]) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    if (ip_parts[1] < start_ip_parts[1] || ip_parts[1] > end_ip_parts[1]) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    if (ip_parts[2] < start_ip_parts[2] || ip_parts[2] > end_ip_parts[2]) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    if (ip_parts[3] < start_ip_parts[3] || ip_parts[3] > end_ip_parts[3]) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    printf("IP address is within the range: %s\n", ip);

    return 0;
}