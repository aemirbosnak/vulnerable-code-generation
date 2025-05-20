//Gemma-7B DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    system("clear");
    system("echo \"Welcome to the C System Administration Interface!\"");
    system("echo \"Please select an option below:\" ");

    char choice;
    printf("1. View System Information\n");
    printf("2. Modify User Permissions\n");
    printf("3. Install New Software\n");
    printf("4. Update System Files\n");
    printf("5. Backup Data\n");

    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            system("echo \"System Information:\n");
            system("uname -a");
            system("free -m");
            system("df -h");
            break;
        case '2':
            system("echo \"Modify User Permissions:\n");
            system("usermod -l");
            break;
        case '3':
            system("echo \"Install New Software:\n");
            system("apt-get update");
            system("apt-get install");
            break;
        case '4':
            system("echo \"Update System Files:\n");
            system("apt-get update");
            system("apt-get upgrade");
            break;
        case '5':
            system("echo \"Backup Data:\n");
            system("tar -zcvf backup.tar.gz /");
            break;
        default:
            system("echo \"Invalid choice. Please try again.\n");
    }

    system("pause");
    return 0;
}