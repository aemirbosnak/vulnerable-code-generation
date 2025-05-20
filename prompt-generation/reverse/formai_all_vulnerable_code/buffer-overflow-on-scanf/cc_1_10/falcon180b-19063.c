//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 1000

typedef struct {
    int top;
    int stack[MAX_QR_CODE_SIZE];
} Stack;

void push(Stack *s, int x) {
    if (s->top >= MAX_QR_CODE_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(0);
    }
    s->stack[++s->top] = x;
}

int pop(Stack *s) {
    if (s->top <= 0) {
        printf("Stack Underflow!\n");
        exit(0);
    }
    return s->stack[s->top--];
}

int isEmpty(Stack *s) {
    return s->top <= 0;
}

void qrCodeReader(char *qrCode) {
    Stack s;
    s.top = -1;

    int len = strlen(qrCode);
    int i = 0;

    while (i < len) {
        char c = qrCode[i++];
        if (c == '[') {
            push(&s, 0);
        } else if (c == ']') {
            int count = pop(&s);
            printf(" %d\n", count);
        } else if (c >= '0' && c <= '9') {
            int num = c - '0';
            int count = 0;

            while (i < len && qrCode[i] >= '0' && qrCode[i] <= '9') {
                count = count * 10 + qrCode[i++] - '0';
            }

            push(&s, num + count);
        } else {
            printf("Invalid QR Code!\n");
            exit(0);
        }
    }
}

int main() {
    char qrCode[MAX_QR_CODE_SIZE];
    printf("Enter QR Code: ");
    scanf("%s", qrCode);

    qrCodeReader(qrCode);

    return 0;
}