//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void show_menu() {
    printf("\n------ Shape Shifting System Admin Tool ------\n");
    printf("1. Check System Uptime\n");
    printf("2. Check Disk Usage\n");
    printf("3. Check Network Configuration\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void check_uptime() {
    FILE *fp;
    char buffer[128];

    fp = popen("uptime", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return;
    }

    printf("\nSystem Uptime:\n");
    while (fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void check_disk_usage() {
    struct statvfs stat;

    if (statvfs("/", &stat) != 0) {
        // Error handling
        perror("statvfs");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    printf("\nDisk Usage:\n");
    printf("Total: %.2f GB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used: %.2f GB\n", used / (1024.0 * 1024.0 * 1024.0));
    printf("Free: %.2f GB\n", free / (1024.0 * 1024.0 * 1024.0));
}

void check_network_config() {
    struct ifaddrs *addrinfo, *temp;
    getifaddrs(&addrinfo);
    temp = addrinfo;

    printf("\nNetwork Configuration:\n");
    while (temp != NULL) {
        if (temp->ifa_addr->sa_family == AF_INET) {
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &((struct sockaddr_in *)temp->ifa_addr)->sin_addr, ip, sizeof(ip));
            printf("Interface: %s, IP Address: %s\n", temp->ifa_name, ip);
        }
        temp = temp->ifa_next;
    }
    freeifaddrs(addrinfo);
}

int main() {
    int choice;
    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_uptime();
                break;
            case 2:
                check_disk_usage();
                break;
            case 3:
                check_network_config();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}