//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct intrusion_log{
    char ip[16];
    char datetime[30];
    char message[100];
};

struct intrusion_log logs[50];
int num_logs = 0;

void log_intrusion(char *ip_addr, char *message){
    struct tm *local;
    time_t t = time(NULL);
    local = localtime(&t);

    sprintf(logs[num_logs].ip, "%s", ip_addr);
    sprintf(logs[num_logs].datetime, "%04d-%02d-%02d %02d:%02d:%02d", local->tm_year + 1900,
            local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
    sprintf(logs[num_logs].message, "%s", message);

    num_logs++;
}

int is_ip_blocked(char *ip_addr){
    int i;
    for(i = 0; i < num_logs; i++){
        if(strcmp(ip_addr, logs[i].ip) == 0){
            //Check if the IP was blocked in the last 10 minutes
            struct tm log_time;
            memset(&log_time, 0, sizeof(struct tm));
            strptime(logs[i].datetime, "%Y-%m-%d %H:%M:%S", &log_time);
            time_t log_t = mktime(&log_time);

            time_t t = time(NULL);
            double diff = difftime(t, log_t);
            if(diff < 600){
                printf("INTRUSION DETECTED: %s was blocked due to %s\n", ip_addr, logs[i].message);
                return 1;
            }
        }
    }
    return 0;
}

void block_ip(char *ip_addr){
    log_intrusion(ip_addr, "exceeding maximum login attempts");
    printf("%s is now blocked for 10 minutes\n", ip_addr);
}

int main(){
    printf("Cyberpunk Intrusion Detection System\n");
    printf("Welcome to the Matrix...\n\n");

    char ip_addr[16];
    int i;
    for(i = 0; i < 5; i++){ //simulate 5 login attempts in a row
        printf("Enter IP Address: ");
        scanf("%s", ip_addr);

        if(is_ip_blocked(ip_addr)){
            continue;
        }

        //Simulate random login success/failure
        srand(time(NULL));
        if(rand() % 2 == 0){
            printf("Login Failed. Number of Attempts Remaining: %d\n\n", 4 - i);
            if(i == 4){
                block_ip(ip_addr);
            }

        }else{
            printf("Login Successful.\n\n");
            break;
        }
    }
    return 0;
}