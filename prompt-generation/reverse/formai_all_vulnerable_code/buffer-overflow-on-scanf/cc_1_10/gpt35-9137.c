//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
/*
        ________  ________   ________  ________  ________  ___  ___  ___       ________  ___  ___  ________  ___     
       |\   ____\|\   __  \ |\   __  \|\   ____\|\   __  \|\  \|\  \|\  \     |\   ____\|\  \|\  \|\   __  \|\  \    
        \ \  \___|\ \  \|\  \\ \  \|\  \ \  \___|\ \  \|\  \ \  \\\  \ \  \    \ \  \___|\ \  \\\  \ \  \|\  \ \  \   
         \ \_____  \ \  \\\  \\ \  \\\  \ \  \  __\ \   ____\ \  \\\  \ \  \    \ \  \    \ \  \\\  \ \   _  _\ \  \  
          \|____|\  \ \  \\\  \\ \  \\\  \ \  \|\  \ \  \___|\ \  \\\  \ \  \____\ \  \____\ \  \\\  \ \  \\  \\ \  \ 
            ____\_\  \ \_______\\ \_______\ \_______\ \__\    \ \_______\ \_______\ \_______\ \_______\ \__\\ _\\ \__\
           |\_________\|_______| \|_______|\|_______|\|__|     \|_______|\|_______|\|_______|\|_______|\|__|\|__|\|__|
           \|_________|                                                                                                  
           
           
           This is a unique C firewall program that allows only a certain IP range to pass through.
           It logs the incoming traffic and blocks IP addresses from outside the range.
           It also has a message system to notify the user of any blocked IPs or potential security threats.
           
           Artistic Style:
           
           The sky is dark and the stars are shining bright,
           as the firewall logs another incoming byte.
           It checks the IP and compares it without fright,
           and blocks the bad guys with all its might.
           
           The message system alerts me with a fright,
           of potential threats lurking in the night.
           But I rest easy knowing my firewall is tight,
           protecting my network with all its light.
           
           So if you try to hack or cause any blight,
           beware of my firewall, it's not polite.
           
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LOG_FILE "firewall_log.txt"
#define MESSAGE_FILE "firewall_messages.txt"

#define BLOCKED_IP "192.168.0.25"
#define IP_RANGE_START "192.168.0.1"
#define IP_RANGE_END "192.168.0.20"

void log_traffic(char* ip_address, char* action, char* message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    fprintf(log_file, "IP: %s | Action: %s | Message: %s\n", ip_address, action, message);
    fclose(log_file);
}

void send_message(char* message) {
    FILE *message_file = fopen(MESSAGE_FILE, "a");
    fprintf(message_file, "%s\n", message);
    fclose(message_file);
}

bool is_in_range(char* ip_address) {
    int start_ip[4] = {192, 168, 0, 1};
    int end_ip[4] = {192, 168, 0, 20};
    int ip[4];
    sscanf(ip_address, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    for (int i = 0; i < 4; i++) {
        if (ip[i] < start_ip[i] || ip[i] > end_ip[i]) {
            return false;
        }
    }
    return true;
}

bool is_blocked(char* ip_address) {
    return strcmp(ip_address, BLOCKED_IP) == 0;
}

int main() {
    char ip_address[16];
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    
    if (is_blocked(ip_address)) {
        printf("IP %s is blocked. Access denied.\n", ip_address);
        log_traffic(ip_address, "Blocked", "IP is on the blocked list.");
        send_message("Potential security threat: Blocked IP attempted to access network.");
        return 0;
    }
    
    if (!is_in_range(ip_address)) {
        printf("IP %s is outside of the allowed range. Access denied.\n", ip_address);
        log_traffic(ip_address, "Blocked", "IP is outside of allowed range.");
        send_message("Potential security threat: IP outside of allowed range attempted to access network.");
        return 0;
    }
    
    printf("Access granted. Welcome, IP %s.\n", ip_address);
    log_traffic(ip_address, "Granted", "Access granted.");
    
    return 0;
}