//Falcon-180B DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_ATTRIBUTES 100
#define MAX_RULES 100
#define MAX_RULE_LENGTH 1000

typedef struct {
    int item;
    int count;
} TItem;

typedef struct {
    int attribute;
    int value;
} TAttribute;

typedef struct {
    int attribute;
    int value;
    int count;
} TRule;

int main() {
    int numItems, numAttributes, numRules, i, j, k;
    TItem items[MAX_ITEMS];
    TAttribute attributes[MAX_ATTRIBUTES];
    TRule rules[MAX_RULES];

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    printf("Enter items:\n");
    for (i = 0; i < numItems; i++) {
        scanf("%d", &items[i].item);
        items[i].count = 0;
    }

    printf("Enter number of attributes: ");
    scanf("%d", &numAttributes);

    printf("Enter attributes:\n");
    for (i = 0; i < numAttributes; i++) {
        scanf("%d", &attributes[i].attribute);
        scanf("%d", &attributes[i].value);
    }

    printf("Enter number of rules:\n");
    scanf("%d", &numRules);

    printf("Enter rules:\n");
    for (i = 0; i < numRules; i++) {
        scanf("%d", &rules[i].attribute);
        scanf("%d", &rules[i].value);
        scanf("%d", &rules[i].count);
    }

    for (i = 0; i < numItems; i++) {
        for (j = 0; j < numAttributes; j++) {
            for (k = 0; k < numRules; k++) {
                if (items[i].item == rules[k].value && attributes[j].attribute == rules[k].attribute && attributes[j].value == rules[k].value) {
                    items[i].count += rules[k].count;
                }
            }
        }
    }

    printf("Mined data:\n");
    for (i = 0; i < numItems; i++) {
        printf("%d: %d\n", items[i].item, items[i].count);
    }

    return 0;
}