//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to System Administration Example Program!\n");
  
  // Creating a new user
  char username[20];
  printf("Enter the username of the new user: ");
  scanf("%s", username);
  char uid[10];
  printf("Enter the UID for the new user: ");
  scanf("%s", uid);
  char homeDir[50];
  printf("Enter the home directory for the new user: ");
  scanf("%s", homeDir);
  char shell[50];
  printf("Enter the login shell for the new user: ");
  scanf("%s", shell);
  char adduser[100] = "sudo adduser ";
  strcat(adduser, username);
  strcat(adduser, " --uid ");
  strcat(adduser, uid);
  strcat(adduser, " --home ");
  strcat(adduser, homeDir);
  strcat(adduser, " --shell ");
  strcat(adduser, shell);
  system(adduser);
  
  // Displaying system information
  char uname[10] = "uname -a";
  printf("System information:\n");
  system(uname);
  char cpuinfo[50] = "cat /proc/cpuinfo | grep 'model name' | uniq";
  printf("\nCPU information:\n");
  system(cpuinfo);
  char meminfo[20] = "free -m";
  printf("\nMemory Information:\n");
  system(meminfo);
  
  // Updating system packages
  char update[20] = "sudo apt update";
  printf("\nUpdating system packages...\n");
  system(update);
  char upgrade[25] = "sudo apt upgrade -y";
  printf("\nUpgrading system packages...\n");
  system(upgrade);
  
  // Checking network connection
  char ping[50];
  printf("\nEnter the website URL to check connection: ");
  scanf("%s", ping);
  char pingCommand[100] = "ping -c 3 ";
  strcat(pingCommand, ping);
  printf("\nChecking network connection...\n");
  if(system(pingCommand) == 0) {
    printf("Connection successful!\n");
  }
  else {
    printf("Connection failed!\n");
  }
  
  // Creating a backup
  char backupDir[50];
  printf("\nEnter the directory path for backup: ");
  scanf("%s", backupDir);
  char backupCommand[100] = "sudo tar czf ";
  strcat(backupCommand, backupDir);
  strcat(backupCommand, "/backup.tar.gz");
  strcat(backupCommand, " /home/");
  printf("\nCreating backup...\n");
  system(backupCommand);
  
  // System logs
  char logs[20] = "sudo cat /var/log/syslog";
  printf("\nSystem logs:\n");
  system(logs);
  
  printf("\nProgram execution complete!\n");
  return 0;
}