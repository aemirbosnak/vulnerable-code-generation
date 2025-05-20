//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the Happy Firewall program!");
    char ip_address[15], allow_list[100], deny_list[100];
    int choice, length, i, j, flag = 0;
    printf("Please enter the IP address you wish to block:");
    scanf("%s", ip_address);
    printf("The IP address you entered is %s\n", ip_address);
    printf("Would you like to: \n1. Add IP address to Allow List\n2. Add IP Address to Deny List\nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        FILE *fptr1;
        fptr1 = fopen("allow.txt", "a");
        if (fptr1 == NULL) {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr1, "%s", ip_address);
        printf("IP address added to Allow List successfully!\n");
        fclose(fptr1);
    }
    else if (choice == 2) {
        FILE *fptr2;
        fptr2 = fopen("deny.txt", "a");
        if (fptr2 == NULL) {
            printf("Error!");
            exit(1);
        }
        fprintf(fptr2, "%s", ip_address);
        printf("IP address added to Deny List successfully!\n");
        fclose(fptr2);
    }
    else {
        printf("Invalid choice entered!\n");
    }
    printf("The current Allow List is:\n");
    FILE *fptr3;
    fptr3 = fopen("allow.txt", "r");
    if (fptr3 == NULL) {
        printf("Error! File not found!");
        exit(1);
    }
    while (fgets(allow_list, sizeof(allow_list), fptr3)) { //read each line from allow.txt and print
        printf("%s", allow_list);
    }
    fclose(fptr3);
    printf("The current Deny List is:\n");
    FILE *fptr4;
    fptr4 = fopen("deny.txt", "r");
    if (fptr4 == NULL) {
        printf("Error! File not found!");
        exit(1);
    }
    while (fgets(deny_list, sizeof(deny_list), fptr4)) { //read each line from deny.txt and print
        printf("%s", deny_list);
    }
    fclose(fptr4);
    printf("Checking if IP address is allowed...\n");
    length = strlen(ip_address);
    FILE *fptr5;
    fptr5 = fopen("allow.txt", "r");
    if (fptr5 == NULL) {
        printf("Error! File not found!");
        exit(1);
    }
    while (fgets(allow_list, sizeof(allow_list), fptr5)) { //read each line from allow.txt 
        if (strlen(allow_list) == length) { //check if length is same
            for (i = 0; i < length; i++) { //check each character
                if (ip_address[i] != allow_list[i]) { //if any one character doesn't match, assign flag as 0
                    flag = 0;
                    break;
                }
                else {
                    flag = 1; //if all characters match, assign flag as 1
                }
            }
        }
        if (flag == 1) { //if flag is 1, that means the IP address matches with the Allow List
            printf("IP address is allowed!\n");
            break;
        }
    }
    fclose(fptr5);
    if (flag == 0) { //if flag is 0, that means the IP address did not match with the Allow List, so check the Deny List
        printf("IP address is not allowed, checking the Deny List...\n");
        length = strlen(ip_address);
        FILE *fptr6;
        fptr6 = fopen("deny.txt", "r");
        if (fptr6 == NULL) {
            printf("Error! File not found!");
            exit(1);
        }
        while (fgets(deny_list, sizeof(deny_list), fptr6)) { //read each line from deny.txt 
            if (strlen(deny_list) == length) { //check if length is same
                for (i = 0; i < length; i++) { //check each character
                    if (ip_address[i] != deny_list[i]) { //if any one character doesn't match, assign flag as 0
                        flag = 0;
                        break;
                    }
                    else {
                        flag = 1; //if all characters match, assign flag as 1
                    }
                }
            }
            if (flag == 1) { //if flag is 1, that means the IP address matches with the Deny List
                printf("IP address is in the Deny List, access denied!\n");
                break;
            }
        }
        fclose(fptr6);
        if (flag == 0) { //if flag is still 0, that means the IP address is neither in the Allow List nor in the Deny List
            printf("IP address is not in any list, access denied!\n");
        }
    }
    return 0;
}