//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1000

struct network_data{
    char ip[16];
    char port[6];
    char username[20];
    char password[20];
};

void log_message(char *message){
    FILE *log_file;
    log_file = fopen("log.txt", "a");
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

bool is_valid_ip(char *ip_address){
    int a, b, c, d;
    if(sscanf(ip_address, "%d.%d.%d.%d", &a, &b, &c, &d) != 4){
        return false;
    }
    if(a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255){
        return false;
    }
    return true;
}

bool is_valid_port(char *port){
    int p = atoi(port);
    if(p < 1 || p > 65535){
        return false;
    }
    return true;
}

bool is_in_blacklist(char *ip_address){
    FILE *file;
    char line[MAX_SIZE];
    file = fopen("blacklist.txt", "r");
    while(fgets(line, sizeof(line), file)){
        if(strncmp(line, ip_address, strlen(ip_address)) == 0){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

bool check_login_attempts(char *ip_address, char *username, char *password){
    FILE *file;
    char line[MAX_SIZE];
    file = fopen("log.txt", "r");
    while(fgets(line, sizeof(line), file)){
        if(strncmp(line, ip_address, strlen(ip_address)) == 0 && strncmp(line+strlen(ip_address)+1, username, strlen(username)) == 0 && strncmp(line+strlen(ip_address)+strlen(username)+2, password, strlen(password)) == 0){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

void add_to_blacklist(char *ip_address){
    FILE *file;
    file = fopen("blacklist.txt", "a");
    fprintf(file, "%s\n", ip_address);
    fclose(file);
}

void parse_data(char *buffer){
    char *ip_address;
    char *port;
    char *username;
    char *password;
    struct network_data data;

    ip_address = strtok(buffer, ",");
    port = strtok(NULL, ",");
    username = strtok(NULL, ",");
    password = strtok(NULL, ",");

    printf("IP address: %s\n", ip_address);
    printf("Port: %s\n", port);
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);

    if(!is_valid_ip(ip_address)){
        printf("Invalid IP address\n");
        log_message("Invalid IP address");
        return;
    }

    if(!is_valid_port(port)){
        printf("Invalid port\n");
        log_message("Invalid port");
        return;
    }

    if(is_in_blacklist(ip_address)){
        printf("IP address is in blacklist\n");
        log_message("IP address is in blacklist");
        return;
    }

    if(check_login_attempts(ip_address, username, password)){
        printf("Successful login attempt\n");
        log_message("Successful login attempt");
    }
    else{
        printf("Failed login attempt\n");
        log_message("Failed login attempt");
        add_to_blacklist(ip_address);
    }

}

int main(){
    char buffer[MAX_SIZE];
    while(true){
        printf("Enter data to parse: ");
        fgets(buffer, MAX_SIZE, stdin);
        if(strcmp(buffer, "exit\n") == 0){
            break;
        }
        parse_data(buffer);
    }
    return 0;
}