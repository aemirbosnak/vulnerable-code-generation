//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define _BV(x) (1 << (x))

struct TuringHash {
    uint64_t state;
    uint8_t *pos;
    uint8_t *end;
};

static uint64_t TuringHash_f(uint64_t state, uint8_t input) {
    uint64_t newstate = state;
    for (int i = 0; i < 8; ++i) {
        newstate ^= input & _BV(i);
        input >>= 1;
    }
    return newstate;
}

static uint64_t TuringHash_g(uint64_t state) {
    uint64_t newstate = state;
    for (int i = 0; i < 64; ++i) {
        if (state & _BV(i)) {
            if (i < 56) {
                newstate ^= _BV(i+8);
            } else {
                newstate ^= _BV(i-56);
            }
        }
    }
    return newstate;
}

static uint64_t TuringHash_h(uint64_t state) {
    uint64_t newstate = state;
    newstate = TuringHash_g(newstate);
    newstate = TuringHash_f(newstate, (uint8_t)(state >> 56));
    return newstate;
}

static void TuringHash_reset(struct TuringHash *ctx) {
    ctx->state = 0;
    ctx->pos = ctx->end;
}

static void TuringHash_update(struct TuringHash *ctx, const uint8_t *data, size_t len) {
    while (len--) {
        ctx->state = TuringHash_h(ctx->state);
        *ctx->pos++ = TuringHash_f(ctx->state, *data++);
        if (ctx->pos == ctx->end) {
            ctx->pos = ctx->end = data;
        }
    }
}

static void TuringHash_final(uint8_t *digest, struct TuringHash *ctx) {
    ctx->state = TuringHash_h(ctx->state);
    while (ctx->pos != ctx->end) {
        *ctx->pos++ = TuringHash_f(ctx->state, 0);
    }
    memcpy(digest, ctx->end, 8);
}

int main(int argc, char **argv) {
    uint8_t digest[8];
    struct TuringHash ctx;
    ctx.pos = ctx.end = (uint8_t *)malloc(1024);
    if (!ctx.pos) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    TuringHash_reset(&ctx);
    TuringHash_update(&ctx, (uint8_t *)"The Turing Hash Function", 24);
    TuringHash_final(digest, &ctx);
    printf("Turing hash: ");
    for (size_t i = 0; i < 8; ++i) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    free(ctx.pos);
    return EXIT_SUCCESS;
}