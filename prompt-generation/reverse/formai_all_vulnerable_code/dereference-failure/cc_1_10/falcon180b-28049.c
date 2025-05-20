//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    char *value;
} Cookie;

typedef struct {
    int count;
    Cookie *cookies;
} CookieJar;

CookieJar *createCookieJar() {
    CookieJar *jar = malloc(sizeof(CookieJar));
    jar->count = 0;
    jar->cookies = malloc(MAX_SIZE * sizeof(Cookie));
    return jar;
}

void addCookie(CookieJar *jar, char *name, char *value) {
    if (jar->count >= MAX_SIZE) {
        printf("Cookie jar is full. Cannot add more cookies.\n");
        return;
    }

    Cookie *cookie = &jar->cookies[jar->count];
    cookie->name = strdup(name);
    cookie->value = strdup(value);
    jar->count++;
}

void printCookies(CookieJar *jar) {
    printf("Cookies:\n");
    for (int i = 0; i < jar->count; i++) {
        printf("%s = %s\n", jar->cookies[i].name, jar->cookies[i].value);
    }
}

void destroyCookieJar(CookieJar *jar) {
    for (int i = 0; i < jar->count; i++) {
        free(jar->cookies[i].name);
        free(jar->cookies[i].value);
    }
    free(jar->cookies);
    free(jar);
}

int main() {
    CookieJar *jar = createCookieJar();

    addCookie(jar, "username", "john_doe");
    addCookie(jar, "password", "secret_password");

    printCookies(jar);

    destroyCookieJar(jar);

    return 0;
}