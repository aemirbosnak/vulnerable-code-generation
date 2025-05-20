//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *ip;
    struct Node *next;
} Node;

Node* createNode(char *ip_address) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->ip = (char*) malloc(strlen(ip_address) + 1);
    strcpy(node->ip, ip_address);
    node->next = NULL;
    return node;
}

void printNodes(Node *head) {
    Node *currNode = head;
    printf("The network has the following devices:\n");
    while (currNode != NULL) {
        printf("%s\n", currNode->ip);
        currNode = currNode->next;
    }
}

int main() {
    printf("Welcome to the Network Topology Mapper!\n\n");
    printf("Please enter the IP addresses of the devices on your network: \n");
    Node *head = NULL;
    char ip_address[32];
    while (1) {
        scanf("%s", ip_address);
        if (strcmp(ip_address, "done") == 0) {
            break;
        }
        Node *node = createNode(ip_address);
        if (head == NULL) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }
    }
    printf("Mapping the network...\n\n");
    printf("Unfortunately, due to budget cuts, we were unable to provide an actual network mapping function.\n");
    printf("Instead, please enjoy this artistic interpretation of your network:\n\n");
    printf("            _,.\n");
    printf("    _..._.-`-`--/|\\\n");
    printf("  .'    ` / '-\"'  . )\n");
    printf(" / _  __/ /' _ _`-'\n");
    printf(" |/_o(_/  |`' |_)|\n");
    printf("  |       `--'| \\\n");
    printf("  ,'            `-\\\n");
    printf(" ,'                `.\n");
    printf("\n");
    printf("Thank you for using the Network Topology Mapper! Come back soon!\n\n");
    printNodes(head);
    return 0;
}