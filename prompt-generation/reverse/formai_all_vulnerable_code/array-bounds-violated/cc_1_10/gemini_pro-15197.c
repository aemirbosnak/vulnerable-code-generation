//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gladiator's Vault
#define VAULT_SIZE 1024

// The Bone Charms
struct Charm {
    int n1;
    int n2;
};

// The Dark Ritual
struct Ritual {
    int n1;
    int n2;
};

// The Oath of Blood
int oath[VAULT_SIZE];

// The Scrolls of Wisdom
struct Scroll {
    char message[1024];
};

// The Guardians of the Vault
int guardians[VAULT_SIZE];

// The Path to Enlightenment
int path[VAULT_SIZE];

// The Key to the Vault
int key;

// The Gate of Shadows
int gate;

// The Portal to Oblivion
int portal;

// The Ritual of Shadows
void ritual(struct Ritual *r) {
    r->n1 = rand() % VAULT_SIZE;
    r->n2 = rand() % VAULT_SIZE;
}

// The Oath of Blood
void oath_of_blood(int n) {
    oath[n] = 1;
}

// The Scrolls of Wisdom
void scroll(struct Scroll *s) {
    strcpy(s->message, "The key to the vault lies in the path of the guardians.");
}

// The Guardians of the Vault
void guardians_of_the_vault(int n) {
    guardians[n] = 1;
}

// The Path to Enlightenment
void path_to_enlightenment(int n) {
    path[n] = 1;
}

// The Key to the Vault
void key_to_the_vault(int n) {
    key = n;
}

// The Gate of Shadows
void gate_of_shadows(int n) {
    gate = n;
}

// The Portal to Oblivion
void portal_to_oblivion(int n) {
    portal = n;
}

// The Bone Charms
struct Charm bone_charms(int n1, int n2) {
    struct Charm c;
    c.n1 = n1;
    c.n2 = n2;
    return c;
}

// The Gladiator's Vault
int gladiators_vault(struct Charm *c) {
    if (c->n1 == key && c->n2 == gate) {
        return 1;
    } else {
        return 0;
    }
}

// The Main Ritual
int main() {
    struct Ritual r;
    int i;

    // The Dark Ritual
    ritual(&r);

    // The Oath of Blood
    oath_of_blood(r.n1);

    // The Scrolls of Wisdom
    struct Scroll s;
    scroll(&s);

    // The Guardians of the Vault
    guardians_of_the_vault(r.n2);

    // The Path to Enlightenment
    path_to_enlightenment(r.n1 + r.n2);

    // The Key to the Vault
    key_to_the_vault(r.n1 * r.n2);

    // The Gate of Shadows
    gate_of_shadows(r.n1 - r.n2);

    // The Portal to Oblivion
    portal_to_oblivion(r.n1 ^ r.n2);

    // The Gladiator's Vault
    struct Charm c = bone_charms(key, gate);
    int result = gladiators_vault(&c);

    // The Final Judgment
    if (result) {
        printf("The vault has been opened.");
    } else {
        printf("The vault remains closed.");
    }

    return 0;
}