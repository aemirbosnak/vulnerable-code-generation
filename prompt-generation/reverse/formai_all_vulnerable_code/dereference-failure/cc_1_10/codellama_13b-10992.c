//Code Llama-13B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
void pk_gen(unsigned char *p, unsigned char *q) {
    unsigned char temp;
    unsigned char *key = malloc(sizeof(unsigned char) * 256);

    for (int i = 0; i < 256; i++) {
        temp = rand() % 256;
        key[i] = temp;
    }

    *p = key[0];
    *q = key[1];

    free(key);
}

void pk_enc(unsigned char *m, unsigned char *c, unsigned char *p) {
    unsigned char temp;
    unsigned char *key = malloc(sizeof(unsigned char) * 256);

    for (int i = 0; i < 256; i++) {
        temp = (unsigned char) (m[i] ^ *p);
        key[i] = temp;
    }

    *c = key[0];

    free(key);
}

void pk_dec(unsigned char *c, unsigned char *m, unsigned char *q) {
    unsigned char temp;
    unsigned char *key = malloc(sizeof(unsigned char) * 256);

    for (int i = 0; i < 256; i++) {
        temp = (unsigned char) (c[i] ^ *q);
        key[i] = temp;
    }

    *m = key[0];

    free(key);
}

int main() {
    unsigned char p[256];
    unsigned char q[256];
    unsigned char m[256];
    unsigned char c[256];

    pk_gen(p, q);

    for (int i = 0; i < 256; i++) {
        m[i] = (unsigned char) rand() % 256;
    }

    pk_enc(m, c, p);

    pk_dec(c, m, q);

    for (int i = 0; i < 256; i++) {
        printf("%d ", m[i]);
    }

    return 0;
}