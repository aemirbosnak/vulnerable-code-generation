//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHS_MAX_ITEMS 1000
#define WHS_MAX_NAME_LEN 25

typedef struct {
    char name[WHS_MAX_NAME_LEN + 1];
    int stock;
} WHS_ITEM;

void error_handler(const char* msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
    exit(EXIT_FAILURE);
}

int main() {
    WHS_ITEM warehouse[WHS_MAX_ITEMS] = {0};
    char command[10];
    int idx, qty;

    while (1) {
        printf("[WHS] > ");
        scanf("%s", command, sizeof(command) / sizeof(command[0]));
        switch (*command) {
            case 'A':
                scanf("%d %s %d", &idx, command + 1, &qty);
                if (idx >= 0 && idx < WHS_MAX_ITEMS && qty > 0) {
                    strncpy(warehouse[idx].name, command + 1, sizeof(warehouse[idx].name) / sizeof(warehouse[idx].name[0]));
                    warehouse[idx].stock = qty;
                } else {
                    error_handler("Invalid index or negative stock.");
                }
                break;

            case 'R':
                scanf("%d %s", &idx, command + 1);
                if (idx >= 0 && idx < WHS_MAX_ITEMS) {
                    printf("[WHS] %s: %d\n", warehouse[idx].name, warehouse[idx].stock);
                } else {
                    error_handler("Invalid index.");
                }
                break;

            case 'T':
                scanf("%s", command + 1);
                for (int i = 0; i < WHS_MAX_ITEMS; ++i) {
                    if (strstr(warehouse[i].name, command + 1)) {
                        printf("[WHS] %s: %d\n", warehouse[i].name, warehouse[i].stock);
                    }
                }
                break;

            case 'X':
                goto EXIT;

            default:
                error_handler("Invalid command.");
        }
    }

EXIT:
    printf("[WHS] Exiting...\n");
    return 0;
}